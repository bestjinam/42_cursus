$(OUT_DIR)/$(DS_DIR)/%.o : $(DS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(DS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(PS_MAIN_DIR)/%.o : $(PS_MAIN_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(PS_MAIN_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(PS_CMD_DIR)/%.o : $(PS_CMD_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(PS_CMD_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(PS_SORTING_DIR)/%.o : $(PS_SORTING_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(PS_SORTING_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(TRG_DIR)/%.o : $(TRG_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(TRG_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/$(BONUS_DIR)/%.o : $(BONUS_DIR)/%.c
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OUT_DIR)/$(BONUS_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@
