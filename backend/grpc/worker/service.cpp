#include "service.h"


std::optional<std::string> WorkerService::validateMovie(const MovieRPC& movie) {
    if (movie.name().empty())
        return "name is empty";

    if (!movie.has_filtersrpc())
        return "filtersrpc is missing";

    const FiltersRPC& f = movie.filtersrpc();

    if (f.style().empty())
        return "style is empty";

    if (f.categorymovie().empty())
        return "categorymovie is empty";

    if (f.origin().empty())
        return "origin is empty";

    if (f.pace().empty())
        return "pace is empty";

    if (movie.year() < 1888 || movie.year() > 2100)
        return "year is invalid";

    if (f.rate() < 0.0 || f.rate() > 10.0)
        return "rate must be between 0 and 10";

    return std::nullopt;
}


Handle WorkerService::Save(const MovieRPC& movie, Storage& storage){
    Handle handle;

    if(WorkerService::validateMovie(movie).has_value()){
        handle.set_status(STATUS::FAILURE);
        handle.set_error("Invalid values to movie. Verify correct payload");
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
            filters.rate(),
            movie.id()
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


Handle WorkerService::Delete(const std::string& id, Storage& storage){
    Handle handle;

    handle.set_status(STATUS::PROCESSING);

    try{
        storage.deleteMovie(id);
    }catch(const std::exception& e){
        handle.set_status(STATUS::FAILURE);
        handle.set_error(e.what());
        return handle;
    }

    handle.set_status(STATUS::DONE);
    handle.set_message("movie deleted");
    return handle;
}