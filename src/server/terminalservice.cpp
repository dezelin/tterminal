#include "terminalservice.h"

#include <cpprest/http_client.h>


TerminalService::TerminalService(const utility::string_t &url)
    : m_listener(url)
{

    m_listener.support(web::http::methods::GET,
                       std::bind(&TerminalService::handle_get, this, std::placeholders::_1));
    m_listener.support(web::http::methods::PUT,
                       std::bind(&TerminalService::handle_put, this, std::placeholders::_1));
    m_listener.support(web::http::methods::POST,
                       std::bind(&TerminalService::handle_post, this, std::placeholders::_1));
    m_listener.support(web::http::methods::DEL,
                       std::bind(&TerminalService::handle_delete, this, std::placeholders::_1));
}

void TerminalService::handle_get(web::http::http_request message)
{
    ucout <<  message.to_string() << std::endl;

    auto paths = web::http::uri::split_path(web::http::uri::decode(message.relative_uri().path()));
    if (paths.empty())
    {
        message.reply(web::http::status_codes::NotFound);
        return;
    }

    message.reply(web::http::status_codes::NotFound);

    /*
    utility::string_t wtable_id = paths[0];
    const utility::string_t table_id = wtable_id;

    // Get information on a specific table.
    auto found = s_tables.find(table_id);
    if (found == s_tables.end())
    {
        message.reply(status_codes::NotFound);
    }
    else
    {
        message.reply(status_codes::OK, found->second->AsJSON());
    }
    */
}

void TerminalService::handle_put(web::http::http_request message)
{
    message.reply(web::http::status_codes::NotFound);
}

void TerminalService::handle_post(web::http::http_request message)
{
    message.reply(web::http::status_codes::NotFound);
}

void TerminalService::handle_delete(web::http::http_request message)
{
    message.reply(web::http::status_codes::NotFound);
}
