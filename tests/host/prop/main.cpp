#include "rsg/actor.hpp"
#include "rsg/mailbox.hpp"
#include "rsg/host.hpp"

#include <stdio.h>
#include <iostream>

XBT_LOG_NEW_CATEGORY(RSG_THRIFT_CLIENT, "Remote SimGrid");
XBT_LOG_NEW_DEFAULT_SUBCATEGORY(RSG_THRIFT_REMOTE_SERVER, RSG_THRIFT_CLIENT , "RSG server (Remote SimGrid)");

using boost::shared_ptr;
using namespace ::simgrid;

int main(int argc, char **argv) {
  const char *prop_msg = rsg::Host::current()->property("message");
  const char *prop_msg_null = rsg::Host::current()->property("nothing");
  XBT_INFO("Host message : %s", prop_msg);
  XBT_INFO("nothing : %s", prop_msg_null);
  rsg::this_actor::quit();
  delete[] prop_msg;
  return 0;
}
