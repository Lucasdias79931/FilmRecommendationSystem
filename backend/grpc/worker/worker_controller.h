#pragma once
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "database_service.grpc.pb.h"
#include "database_service.pb.h"
#include "service.h"

using grpc::ServerContext;
using grpc::Status;


using database_service::DatabaseService;
using database_service::FiltersRPC;
using database_service::Handle;
using database_service::MovieRPC;
using database_service::MoviesRPC;
using database_service::STATUS;
using database_service::GetRequest;

#include "data-structures/storage.h"

class Worker_Controller final : public DatabaseService::Service {
    private:
        Storage& storage;
    public:
        Worker_Controller(Storage& storage):storage(storage){} 

        Status Save(ServerContext* context, const MovieRPC* request, Handle* response) override ;

        Status Delete(ServerContext* context, const GetRequest* request, Handle* response) override ;

        Status GetAll(ServerContext* context, const FiltersRPC* request, MoviesRPC* response) override ;

        Status Get(ServerContext* context, const GetRequest* request, MovieRPC* response) override ;
};