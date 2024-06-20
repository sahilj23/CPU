#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "scheduler.h"
#include <vector>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_post(http_request request) {
    request
        .extract_json()
        .then([request](json::value json_object) {
            std::vector<Process> processes;
            for (auto process : json_object[U("processes")].as_array()) {
                Process p;
                p.id = process[U("id")].as_integer();
                p.burstTime = process[U("burstTime")].as_integer();
                p.arrivalTime = process[U("arrivalTime")].as_integer();
                p.priority = process[U("priority")].as_integer();
                p.remainingTime = process[U("remainingTime")].as_integer();
                processes.push_back(p);
            }

            std::string algorithm = json_object[U("algorithm")].as_string();
            int timeQuantum = json_object[U("timeQuantum")].as_integer();
            
            std::stringstream result;

            if (algorithm == "FCFS") {
                fcfsScheduling(processes, result);
            } else if (algorithm == "SJF") {
                sjfScheduling(processes, result);
            } else if (algorithm == "Priority") {
                priorityScheduling(processes, result);
            } else if (algorithm == "RR") {
                rrScheduling(processes, timeQuantum, result);
            }

            json::value response_data;
            response_data[U("output")] = json::value::string(result.str());

            request.reply(status_codes::OK, response_data);
        })
        .wait();
}

int main() {
    uri_builder uri(U("http://localhost:8080"));
    auto addr = uri.to_uri().to_string();
    http_listener listener(addr);

    listener.support(methods::POST, handle_post);

    try {
        listener
            .open()
            .then([&listener](){ ucout << U("Starting to listen at: ") << listener.uri().to_string() << std::endl; })
            .wait();

        while (true);
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
