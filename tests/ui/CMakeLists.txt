add_executable(ui_tests test_window.cpp)
target_link_libraries(ui_tests PRIVATE catch_main CONAN_PKG::sfml ecs world ui tilemap)

#target_link_libraries(world_tests PRIVATE project_warnings project_options catch_main)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  ui_tests
  TEST_PREFIX
  "ui_tests."
  REPORTER
  xml
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "ui_tests."
  OUTPUT_SUFFIX
  .xml)