#include "pch.h"
#include "CppUnitTest.h"
#include "Studentas.h"
#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentasTests
{
    TEST_CLASS(StudentasCalculationTests)
    {
    public:

        TEST_METHOD(GalutiniaiSkaiciuojamiTeisingai_PagalVidurki)
        {
            // ND: 8, 9, 10 (vidurkis = 9)
            // Egzaminas = 8
            // Galutinis = 0.4 * 9 + 0.6 * 8 = 8.4

            std::vector<int> nd = { 8, 9, 10 };
            Studentas s("Jonas", "Jonaitis", nd, 8);

            Assert::AreEqual(8.4, s.galutinisVid(), 0.0001);
        }

        TEST_METHOD(GalutiniaiSkaiciuojamiTeisingai_PagalMediana)
        {
            // ND: 5, 10, 9, 7 (surūšiuota -> 5,7,9,10)
            // Mediana = (7 + 9) / 2 = 8
            // Egz = 6
            // Galutinis = 0.4 * 8 + 0.6 * 6 = 6.8

            std::vector<int> nd = { 5, 10, 9, 7 };
            Studentas s("Petras", "Petraitis", nd, 6);

            Assert::AreEqual(6.8, s.galutinisMed(), 0.0001);
        }

        TEST_METHOD(TusciamsND_GalutiniaiSkaičiuojamiPagalEgzamina)
        {
            // ND nėra → naudojama taisyklė:
            // galutinis = 0.6 * egz

            std::vector<int> tuscia;
            Studentas s("Empty", "Case", tuscia, 10);

            Assert::AreEqual(6.0, s.galutinisVid(), 0.0001);
            Assert::AreEqual(6.0, s.galutinisMed(), 0.0001);
        }

        TEST_METHOD(KopijavimoKonstruktorius_VeikiaTeisingai)
        {
            std::vector<int> nd = { 10, 10, 10 };
            Studentas original("A", "B", nd, 10);

            Studentas copy(original);

            Assert::AreEqual(original.vardas(), copy.vardas());
            Assert::AreEqual(original.pavarde(), copy.pavarde());
            Assert::AreEqual(original.galutinisVid(), copy.galutinisVid(), 0.0001);
            Assert::AreEqual(original.galutinisMed(), copy.galutinisMed(), 0.0001);
        }

        TEST_METHOD(PriskyrimoOperatorius_VeikiaTeisingai)
        {
            std::vector<int> nd1 = { 1, 2, 3 };
            std::vector<int> nd2 = { 10, 10, 10 };

            Studentas s1("A", "B", nd1, 5);
            Studentas s2("X", "Y", nd2, 10);

            s1 = s2;

            Assert::AreEqual(std::string("X"), s1.vardas());
            Assert::AreEqual(std::string("Y"), s1.pavarde());
            Assert::AreEqual(s2.galutinisVid(), s1.galutinisVid(), 0.0001);
        }
    };
}
