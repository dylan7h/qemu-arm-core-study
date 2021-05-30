export TARGET	:= realview-pb-a8
export TOPDIR	:= ..

TEST_VAR		:= 10

all: setting
	@$(MAKE) -C $(TARGET) --no-print-directory

clean: setting
	@$(MAKE) -C $(TARGET) clean --no-print-directory

distclean:
	rm -rf build/*

run: setting
	@$(MAKE) -C $(TARGET) run --no-print-directory

debug: setting
	@$(MAKE) -C $(TARGET) debug --no-print-directory

info: setting
	@$(MAKE) -C $(TARGET) info --no-print-directory

setting:
	@rm -rf .vscode/settings.json
	@touch .vscode/settings.json
	@echo "{" >> .vscode/settings.json
	@printf "\t\"BUILD_TARGET\": %s\n" "\"$(TARGET)\"" >> .vscode/settings.json
	@echo "}" >> .vscode/settings.json
