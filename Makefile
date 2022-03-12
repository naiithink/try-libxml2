TESTFILE = main
SRCDIR = aboutxml
SRCFILENAME = anxml
BINDIR = bin
CXX = clang++
CXXFLAGS = -g
CXXINCLUDE = -I/usr/include/libxml2
LDFLAGS = -lxml2

make : config
	$(CXX) -c $(CXXINCLUDE) $(SRCDIR)/$(SRCFILENAME).cpp -o $(SRCDIR)/$(SRCFILENAME).o
	$(CXX) $(CXXINCLUDE) $(LDFLAGS) $(CXXFLAGS) $(SRCDIR)/$(SRCFILENAME).o $(TESTFILE).cpp -o $(BINDIR)/$(TESTFILE).out
	@echo
	@echo "----------------------------------------------------------------------------------"
	@echo "\033[1;33mTRY: \033[0;39m \`./$(BINDIR)/$(TESTFILE).out index.xml \"https://www.nasa.gov/rss/dyn/Gravity-Assist.rss\"'"
	@echo "----------------------------------------------------------------------------------"
	@echo
	@echo "\033[1;4mNote\033[0m: uncomment lines in \`$(TESTFILE).cpp' to try \`fetchFile()'     \033[1;31m[MEMORY LEAK WARNING]\033[0;39m"
	@echo

config :
	if [ ! -d $(BINDIR) ]; then mkdir $(BINDIR); fi