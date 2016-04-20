// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include <thrift/protocol/TBinaryProtocol.h>

#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "rsg/RsgServiceImpl.h"
#include "client/RsgClientEngine.hpp"
#include "rsg/actor.hpp"
#include "rsg/mailbox.hpp"
#include "rsg/host.hpp"

#include "xbt.h"
#include "simgrid/s4u.h"

#include <iostream>

XBT_LOG_NEW_CATEGORY(RSG_THRIFT_CLIENT, "Remote SimGrid");
XBT_LOG_NEW_DEFAULT_SUBCATEGORY(RSG_THRIFT_CLIENT_REMOTE, RSG_THRIFT_CLIENT , "RSG server (Remote SimGrid)");

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;
using namespace ::RsgService;

int main(int argc, char **argv) {
  XBT_INFO("hello from Client");
  rsg::Mailbox *mbox = rsg::Mailbox::byName("toto");
  rsg::Actor &self = rsg::Actor::self();
  XBT_INFO("hostname : %s", rsg::Host::current().name().c_str());
  self.send(*mbox,"Do you copy ?");

	self.sleep(42);
  self.execute(8095000000);
  self.quit();
  return 0;
}
