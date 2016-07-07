FILE(REMOVE_RECURSE
  "iotstock_automoc.cpp"
  "iotstock.shell"
  "CMakeFiles/translations"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/translations.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
