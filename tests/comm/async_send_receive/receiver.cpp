// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <thrift/protocol/TBinaryProtocol.h>

#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "rsg/services.hpp"
#include "client/RsgClient.hpp"
#include "rsg/actor.hpp"
#include "rsg/mailbox.hpp"
#include "rsg/host.hpp"

#include "xbt.h"
#include "simgrid/s4u.hpp"

#include <stdio.h>
#include <iostream>

XBT_LOG_NEW_CATEGORY(RSG_THRIFT_CLIENT, "Remote SimGrid");
XBT_LOG_NEW_DEFAULT_SUBCATEGORY(RSG_THRIFT_REMOTE_SERVER, RSG_THRIFT_CLIENT , "RSG server (Remote SimGrid)");

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace ::RsgService;
using namespace ::simgrid;

int main(int argc, char **argv) {
  char *buffer = NULL;
  rsg::Mailbox *mbox = rsg::Mailbox::byName("toto");
  rsg::Comm &comm = rsg::Comm::recv_init(*mbox);
  comm.setDstData((void**)&buffer);
  comm.start();
  rsg::this_actor::execute(8095000000 * 1.999999);
  comm.wait();
  XBT_INFO("Async Received : %s with size of %d ", buffer, (int) strlen(buffer));
  
  free(buffer);
  buffer = NULL;
  
  rsg::Comm &comm2 = rsg::Comm::recv_async(*mbox, (void**)&buffer);
  rsg::this_actor::execute(8095000000);
  comm2.wait();
  XBT_INFO("Async Received : %s with size of %d ", buffer, strlen(buffer));
  
  free(buffer);
  buffer = NULL;
  
  rsg::Comm &comm3 = rsg::Comm::recv_init(*mbox);
  comm3.setDstData((void**)&buffer);
  comm3.start();
  rsg::this_actor::execute(8095000000 * 2);
  comm3.wait();
  XBT_INFO("Async Received : %s with size of %d ", buffer, (int) strlen(buffer));
  
  free(buffer);
  buffer = NULL;
  
  rsg::Comm &comm4 = rsg::Comm::recv_async(*mbox, (void**)&buffer);
  rsg::this_actor::execute(8095000000);
  comm4.wait();
  XBT_INFO("Async Received : %s with size of %d ", buffer, strlen(buffer));
  
  rsg::this_actor::quit();
  return 0;
}
