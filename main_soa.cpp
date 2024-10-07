#include "progargs.hpp"
#include "imagesoa.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        std::string operation = parse_operation(argc, argv);

        if (operation == "info") {
            print_image_metadata(argv[1]);
        } else {
            process_image_soa(argv[1]);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
