
$(OUT_DIR)/$(M_DIR)/%.o : $(M_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(M_DIR)
	$(CC) -c $(CFLAGS) $(RLCFLAGS) $< -o $@

$(OUT_DIR)/$(B_DIR)/%.o : $(B_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(B_DIR)
	$(CC) -c $(CFLAGS) $(RLCFLAGS) $< -o $@

$(OUT_DIR)/$(S_DIR)/%.o : $(S_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(S_DIR)
	$(CC) -c $(CFLAGS) $(RLCFLAGS) $< -o $@

$(OUT_DIR)/$(BUILT_DIR)/%.o : $(BUILT_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(BUILT_DIR)
	$(CC) -c $(CFLAGS) $(RLCFLAGS) $< -o $@
