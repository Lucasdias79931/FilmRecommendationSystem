#pragma once
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "database_service.grpc.pb.h"
#include "database_service.pb.h"

using grpc::ServerContext;
using grpc::Status;


using database_service::DatabaseService;
using database_service::FiltersRPC;
using database_service::Handle;
using database_service::MovieRPC;
using database_service::MoviesRPC;
using database_service::STATUS;
using database_service::GetRequest;