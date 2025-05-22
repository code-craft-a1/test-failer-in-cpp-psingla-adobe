#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{
    // Interface for weather sensor
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
            virtual ~IWeatherSensor() = default; // Virtual destructor
    };

    // Stub class for testing
    class SensorStub : public IWeatherSensor {
        private:
            double temperature;
            int precipitation;
            int humidity;
            int windSpeed;

        public:
            // Constructor to allow configurable sensor values
            SensorStub(double temp, int precip, int hum, int wind)
                : temperature(temp), precipitation(precip), humidity(hum), windSpeed(wind) {}

            double TemperatureInC() const override {
                return temperature;
            }

            int Precipitation() const override {
                return precipitation;
            }

            int Humidity() const override {
                return humidity;
            }

            int WindSpeedKMPH() const override {
                return windSpeed;
            }
    };

    // Function to generate a weather report based on sensor data
    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        int windSpeed = sensor.WindSpeedKMPH();
        double temperature = sensor.TemperatureInC();

        // Default report is "Sunny Day"
        string report = "Sunny Day";

        if (temperature > 25) {
            if (precipitation >= 20 && precipitation < 60) {
                report = "Partly Cloudy";
            } else if (precipitation >= 60 && windSpeed < 50) {
                report = "Heavy Rain";
            } else if (precipitation >= 60 && windSpeed >= 50) {
                report = "Alert, Stormy with heavy rain";
            }
        }
        return report;
    }

    // Test for rainy conditions
    void TestRainy()
    {
        // Simulate rainy conditions: high precipitation and high wind speed
        SensorStub sensor(26, 70, 72, 52);
        string report = Report(sensor);
        cout << "TestRainy Report: " << report << endl;
        assert(report.find("rain") != string::npos); // Ensure "rain" is in the report
    }

    // Test for high precipitation with low wind speed
    void TestHighPrecipitation()
    {
        // Simulate high precipitation (>60) and low wind speed (<50)
        SensorStub sensor(26, 70, 72, 40);
        string report = Report(sensor);
        cout << "TestHighPrecipitation Report: " << report << endl;
        assert(report.length() > 0); // Ensure the report is not empty
        assert(report.find("Heavy Rain") != string::npos); // Ensure "Heavy Rain" is in the report
    }
}

// Entry point for running weather report tests
void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    cout << "All is well (maybe)\n";
}