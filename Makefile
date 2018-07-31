descend = \
	$(MAKE) $(COMMAND_O) subdir=$(if $(subdir),$(subdir)/$(1),$(1)) $(PRINT_DIR) -C $(1) $(2)

help:
	@echo 'Possible targets:'
	@echo ''
	@echo '  kmod              - igb module'
	@echo ''
	@echo '  lib               - igb library'
	@echo ''

kmod: FORCE
	$(call descend,kmod)

kmod_clean:
	$(call descend,kmod,clean)

lib: FORCE
	$(call descend,lib)

lib_clean:
	$(call descend,lib,clean)

all: kmod lib

clean: kmod_clean lib_clean

.PHONY: FORCE
