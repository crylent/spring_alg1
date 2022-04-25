#include "pch.h"
#include "CppUnitTest.h"
#include "../spring_alg1/TreeMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace springtest1
{
	TEST_CLASS(springtest1)
	{
	public:

		TEST_METHOD(TestInsert)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			Assert::AreEqual(0, map->find("death"));
			Assert::AreEqual(1, map->find("pain"));
			Assert::AreEqual(2, map->find("solitude"));
			Assert::AreEqual(3, map->find("suffering"));
		}

		TEST_METHOD(TestWrongInsert)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			try {
				map->insert("death", 0);
			}
			catch (std::exception error) {
				Assert::AreEqual("Key already exists", error.what());
			}
		}

		TEST_METHOD(TestRemove)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			map->remove("pain");
			Assert::AreEqual(0, map->find("death"));
			try {
				map->find("pain");
			}
			catch (std::exception error) {
				Assert::AreEqual("Key does not exists", error.what());
			}
			Assert::AreEqual(2, map->find("solitude"));
			Assert::AreEqual(3, map->find("suffering"));
		}

		TEST_METHOD(TestWrongRemove)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			try {
				map->remove("happiness");
			}
			catch (std::exception error) {
				Assert::AreEqual("Key does not exists", error.what());
			}
		}

		TEST_METHOD(TestSize)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			Assert::AreEqual(size_t(4), map->get_size());
		}

		TEST_METHOD(TestGetKeys)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			std::string keys_expected[4] = { "death", "pain", "solitude", "suffering" };
			std::string* keys = map->get_keys();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (keys_expected[i] == keys[j]) {
						break;
					}
					if (j == 3) {
						Assert::Fail();
					}
				}
			}
		}

		TEST_METHOD(TestGetValues)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			int values_expected[4] = { 0, 1, 2, 3 };
			int* values = map->get_values();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (values_expected[i] == values[j]) {
						break;
					}
					if (j == 3) {
						Assert::Fail();
					}
				}
			}
		}

		TEST_METHOD(TestOutput)
		{
			TreeMap<std::string, int>* map = new TreeMap<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			std::ostringstream stream;
			stream << *map;
			Assert::AreEqual("{\n\tdeath -> 0\n\tpain -> 1\n\tsolitude -> 2\n\tsuffering -> 3\n}\n", stream.str().c_str());
		}
	};
}
