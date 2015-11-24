#ifndef TERMINALSERVICE_H
#define TERMINALSERVICE_H

#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>

class TerminalService
{
public:
    TerminalService(const utility::string_t& url);

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

private:
    void handle_get(web::http::http_request message);
    void handle_put(web::http::http_request message);
    void handle_post(web::http::http_request message);
    void handle_delete(web::http::http_request message);

    web::http::experimental::listener::http_listener m_listener;
};

#endif // TERMINALSERVICE_H
