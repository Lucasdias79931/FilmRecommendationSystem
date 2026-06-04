#include <iostream>
#include <grpcpp/grpcpp.h>

#include "database_service.grpc.pb.h"
#include "database_service.pb.h"

using grpc::ServerContext;
using grpc::Status;

using database_service::DatabaseService;
using database_service::Filters;
using database_service::Handle;
using database_service::Movie;
using database_service::Movies;
using database_service::STATUS;

class Worker_Controller final : public DatabaseService::Service {
public:

    Status Save(ServerContext* context, const Movie* request, Handle* response) override ;

    Status Delete(ServerContext* context, const Movie* request, Handle* response) override ;

    Status GetAll(ServerContext* context, const Filters* request, Movies* response) override ;

    Status Get(ServerContext* context, const Movie* request, Movie* response) override ;
};