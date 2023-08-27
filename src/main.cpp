#include <iostream>
#include <httplib.h>

using namespace httplib;

int main(void) {
  std::cout << "Hello World!";
  Server svr;

  // http://localhost:8080/hi
  svr.Get("/hi", [](const Request & /*req*/, Response &res) {
    res.set_content("Hello World!", "text/plain");
  });

  std::cout << "8080";
  svr.listen("0.0.0.0", 8080);


}
