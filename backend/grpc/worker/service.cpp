#include "service.h"


bool WorkerService::validateMovie(const MovieRPC& movie){
    const Filters& filters = movie.filters();

    
    if(movie.name().empty() || filters.style().empty() || filters.categorymovie().empty() || filters.origin().empty() || filters.pace().empty())
        return false;

    return true;
}


Handle WorkerService::Save(const MovieRPC& movie, Storage& storage){
    Handle handle;

    if(!WorkerService::validateMovie(movie)){
        handle.set_status(STATUS::FAILURE);
        handle.set_error("PAYLOAD ERROR");
        return handle;
    }

    try{
        const Filters& filters = movie.filters();
        Movie m(
            movie.name(),
            stringToCategory(filters.categorymovie()),
            filters.origin(),
            filters.style(),
            filters.pace(),
            movie.year(),
            filters.rate()
        );

        storage.addMovie(m);

        handle.set_status(STATUS::DONE);
        handle.set_message(m.id);
        return handle;
    }catch(const std::exception& e){
        handle.set_status(STATUS::FAILURE);
        handle.set_error(e);
        return handle;
    }
    
}