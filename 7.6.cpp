#include <iostream>
#include <fstream>
#include <vector>

struct FlightData {
    int x;
    int y;
    int command;
};

int main() {
    std::ifstream inputFile("flight_data.txt");
    if (!inputFile) {
        std::cout << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    std::vector<FlightData> flightDataList;
    std::string line;
    while (std::getline(inputFile, line)) {
        FlightData flightData;
        sscanf(line.c_str(), "%d,%d,%d", &flightData.x, &flightData.y, &flightData.command);
        flightDataList.push_back(flightData);
    }

    inputFile.close();

    for (const auto& flightData : flightDataList) {
        std::cout << "Координаты: " << flightData.x << ", " << flightData.y << std::endl;
        std::cout << "Команда: " << flightData.command << std::endl;
        std::cout << std::endl;
    }

    return 0;
}