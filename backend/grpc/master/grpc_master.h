#pragma once
#include <memory>
#include "../grpc_common.h"

using grpc::ClientContext;

class Master {
    private:
        std::unique_ptr<database_service::DatabaseService::Stub> stub_;
        
    public:
        explicit Master(std::shared_ptr<grpc::Channel> channel);

        database_service::Handle Save(const database_service::MovieRPC& movie);

        database_service::Handle Delete(std::string& id);

        database_service::MoviesRPC GetAll(FiltersRPC& filters);
};