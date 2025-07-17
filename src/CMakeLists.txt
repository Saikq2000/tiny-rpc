#aux_source_directory(. SRC_LIST)
set(SRC_LIST 
    mprpcapplication.cc 
    mprpcconfig.cc 
    rpcheader.pb.cc 
    rpcprovider.cc 
    mprpcchannel.cc
    mprpccontroller.cc
    logger.cc
    zookeeperutil.cc)

file(GLOB_RECURSE TINYMUDUO_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/tiny_muduo/*.cc)

set(MPRPC_ALL_SRC ${SRC_LIST} ${TINYMUDUO_SRC})

add_library(mprpc STATIC ${MPRPC_ALL_SRC})

target_link_libraries(mprpc pthread zookeeper_mt mysqlclient)