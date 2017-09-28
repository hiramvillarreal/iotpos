file(REMOVE_RECURSE
  "iotstock_automoc.cpp"
  "iotstock.shell"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/translations.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
