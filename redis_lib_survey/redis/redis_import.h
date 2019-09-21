#pragma once

#include "lib_acl.hpp"

#ifndef _DEBUG
#pragma comment (lib, "acl/lib_acl.lib")
#pragma comment (lib, "acl/lib_protocol.lib")
#pragma comment (lib, "acl/lib_acl_cpp.lib")
#else
#pragma comment (lib, "acl/lib_acl_d.lib")
#pragma comment (lib, "acl/lib_protocol_d.lib")
#pragma comment (lib, "acl/lib_acl_cpp_d.lib")
#endif

