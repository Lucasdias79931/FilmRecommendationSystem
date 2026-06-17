#include "service.h"


bool WorkerService::validateMovie(const MovieRPC& movie){
    const FiltersRPC& filtersrpc = movie.filtersrpc();

    
    if(movie.name().empty() || filtersrpc.style().empty() || filtersrpc.categorymovie().empty() || filtersrpc.origin().empty() || filtersrpc.pace().empty())
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
        const FiltersRPC& filters = movie.filtersrpc();
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
        handle.set_error(e.what());
        return handle;
    }
    
}