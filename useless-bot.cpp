#include <iostream>
#include <string>
#include <boost/python.hpp>
#include <boost/optional.hpp>

class User {
  uint64_t id;
  std::string name;
public:
  User(uint64_t id, const std::string &name) : id(id), name(name) {
  }

  uint64_t getId() const {
    return id;
  }

  const std::string &getName() const {
    return name;
  }
};

class BotCore {
  boost::optional<User> self;
public:
  void on_ready(const User &u) {
    using std::cout;
    using std::endl;
    self = u;

    cout << "Wow! Am I ready!" << endl;
    cout << "My id is " << self->getId() << endl;
    cout << "My name is " << self->getName() << endl;
  }
};

using namespace boost::python;

BOOST_PYTHON_MODULE(useless_bot)
{
    class_<User>("User", init<uint64_t, const std::string &>())
    ;

    class_<BotCore>("BotCore")
        .def("on_ready", &BotCore::on_ready)
    ;
};