file(REMOVE_RECURSE
  "iotpos_automoc.cpp"
  "iotpos.shell"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/translations.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
