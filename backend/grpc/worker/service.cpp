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

void WorkerService::GetAll(const FiltersRPC& filters, Storage& storage, MoviesRPC& movies){

    Filters filters_parse;
    filters_parse.category = stringToCategory(filters.categorymovie());
    filters_parse.origin = filters.origin();
    filters_parse.pace = filters.pace();
    filters_parse.style = filters.style();
    
    try{
        Linked_list<Movie> list_movies = storage.getMovies(filters_parse);

        const Linear_node<Movie>* walk = list_movies.getNode();

        while (walk != nullptr) {
            const Movie& movie = walk->data;

            
            auto* m = movies.add_movies();
            m->set_id(movie.id);
            m->set_name(movie.name);
            m->set_year(movie.year);
            
            
            auto* f = m->mutable_filtersrpc();

            f->set_categorymovie(toString(movie.category));
            f->set_pace(movie.pace);
            f->set_rate(movie.rate);
            f->set_style(movie.style);
            
            walk = walk->next;

        }

    }catch(const std::exception& e){
        movies.set_status(STATUS::FAILURE);
        movies.set_error(e.what());
    }

}