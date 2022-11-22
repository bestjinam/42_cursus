
$(OUT_DIR)/$(M_DIR)/%.o : $(M_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(M_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(B_DIR)/%.o : $(B_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(B_DIR)
	$(CC) -c $(CFLAGS) $< -o $@
