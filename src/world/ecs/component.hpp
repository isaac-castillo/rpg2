#ifndef __component__
#define __component__
class component {

public:
  virtual void receive() = 0;
  virtual ~component() = default;
};
#endif