
$(OUT_DIR)/%.o : %.c
	@mkdir -p $(OUT_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OUT_DIR)/%.o : %.c
	@mkdir -p $(OUT_DIR)
	$(CC) -c $(CFLAGS) $< -o $@
