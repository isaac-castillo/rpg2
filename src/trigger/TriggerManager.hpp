#ifndef trigger__
#define trigger__

#include "action/BaseAction.hpp"

class PollableTrigger {

  virtual bool isActive() = 0;
};

class TriggerManager {

  using TileIndex = int;
  enum class TileTriggerMode { onEnter,
    onExit,
    onTopOf };
  enum class EntityTriggerMode { onInteract,
    onStopInteract,
    onInteracting };
  void addTrigger(action::Action &, TileIndex, TileTriggerMode);
  void addTrigger(action::Action &, Entity &, TileTriggerMode);
  void addTrigger(PollableTrigger, action::Action &);
};

#endif
