install( FILES
  tip.svg
  rotated_tip.svg
  floating_bottom.svg
  floating_top.svg
  panel_top_big.svg
  panel_top.svg
  dialog.svg
DESTINATION  ${DATA_INSTALL_DIR}/iotpos/styles/ )

add_subdirectory(simple)
add_subdirectory(elegant)
#add_subdirectory(serious) #Serious style is incomplete
