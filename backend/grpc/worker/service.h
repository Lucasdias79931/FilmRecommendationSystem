#pragma once
#include <iostream>
#include "data-structures/storage.h"

#include "database_service.grpc.pb.h"
#include "database_service.pb.h"
#include "structs.h"
#include "enums.h"

using database_service::DatabaseService;
using database_service::FiltersRPC;
using database_service::Handle;
using database_service::MovieRPC;
using database_service::MoviesRPC;
using database_service::STATUS;
using database_service::GetRequest;
using database_service::STATUS;

class WorkerService{
    public:
        static bool validateMovie(const MovieRPC& movie);

        static Handle Save(const MovieRPC& movie, Storage& storage);
};

