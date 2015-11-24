
#include "terminalservice.h"

#include <cpprest/json.h>
#include <cpprest/http_listener.h>
#include <cpprest/uri.h>
#include <cpprest/asyncrt_utils.h>

#include <iostream>
#include <memory>
#include <string>

using namespace std;

std::unique_ptr<TerminalService> g_httpService;

void on_initialize(const utility::string_t& address)
{
    // Build our listener's URI from the configured address and the hard-coded path "blackjack/dealer"

    web::http::uri_builder uri(address);
    uri.append_path(U("Terminal"));

    auto addr = uri.to_uri().to_string();
    g_httpService = std::unique_ptr<TerminalService>(new TerminalService(addr));
    g_httpService->open().wait();

    ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
}

void on_shutdown()
{
    g_httpService->close().wait();
}


int main(int argc, char **argv)
{
    utility::string_t port = U("23456");
    if(argc == 2)
        port = argv[1];

    utility::string_t address = U("http://localhost:");
    address.append(port);

    on_initialize(address);
    std::cout << "Press ENTER to exit." << std::endl;

    std::string line;
    std::getline(std::cin, line);

    on_shutdown();
    return 0;
}
