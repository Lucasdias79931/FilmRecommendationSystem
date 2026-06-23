#pragma once
#include "../grpc_common.h"

#include "service.h"

using grpc::Status;



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