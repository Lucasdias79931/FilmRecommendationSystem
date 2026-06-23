#pragma once
#include "../grpc_common.h"
#include "data-structures/storage.h"
#include <optional>



class WorkerService{
    public:
        static std::optional<std::string> validateMovie(const MovieRPC& movie);

        static Handle Save(const MovieRPC& movie, Storage& storage);


        static Handle Delete(const std::string& id, Storage& storage);
        //GetAll(FiltersRPC) returns (MoviesRPC);
        //Get(GetRequest) returns (MovieRPC);
};

