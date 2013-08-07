#include<iostream>
#include<string>
#include<list>
#include<map>
#include<cstdlib> //for std::atof

int parse_cmdline(int argc, char* argv[], std::map<std::string,size_t>& params)
{
	if(argc > 1){
		std::list<std::string>  x(argv+1, argv+argc);

		std::string pname;
		std::string pvalue;
		auto i = x.begin();
		while(i != x.end() ){
			pname = *i; i = x.erase(i);
			if(i != x.end()){
				pvalue = *i; i = x.erase(i);
			}else{
				std::cout << "ERROR: Param(" << pname << ") does not have an associated value" << std::endl;
				return 1;
			}

			if(pname[0] == '-' && isdigit(pvalue[0])){
				pname = pname.substr(1,pname.size());
				auto pi = params.find(pname);
				if(pi != params.end()){
					pi->second = atof(pvalue.c_str());
				}else{
					std::cout << "ERROR: Param(" << pname << ") is not a valid parameter\n";
					std::cout << "  Legal Parameters are:\n    ";
					for(auto pii = params.begin(); pii != params.end(); pii++){
						std::cout << pii->first << ", ";
					}
					std::cout << std::endl;
					return 1;
				}
			}else{
				std::cout << "ERROR: Param(" << pname << ") has syntax error" << std::endl;
				return 1;
			}
		}//while
	}//argc > 1
	return 0;
}

int
main(int argc, char *argv[])
{
	std::map<std::string, size_t> params = {
		{"width",   256},
		{"height",  256},
		{"samples", 1}
	};

	if(int err = parse_cmdline(argc,argv, params)){
		return err;
	}


	const size_t width   = params["width"];
	const size_t height  = params["height"];
	const size_t samples = params["samples"];
	std::cout << "width= " << width << ", height= " << height << ", samples= " << samples << "\n";
	

}
