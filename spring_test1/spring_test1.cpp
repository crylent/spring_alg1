#include "pch.h"
#include "CppUnitTest.h"
#include "../spring_alg1/Map.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace springtest1
{
	TEST_CLASS(springtest1)
	{
	public:

		TEST_METHOD(TestInsert)
		{
			Map<std::string, int>* map = new Map<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			Assert::AreEqual(0, map->find("death"));
			Assert::AreEqual(1, map->find("pain"));
			Assert::AreEqual(2, map->find("solitude"));
			Assert::AreEqual(3, map->find("suffering"));
		}

		TEST_METHOD(TestRemove)
		{
			Map<std::string, int>* map = new Map<std::string, int>();
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

		TEST_METHOD(TestSize)
		{
			Map<std::string, int>* map = new Map<std::string, int>();
			map->insert("death", 0);
			map->insert("pain", 1);
			map->insert("solitude", 2);
			map->insert("suffering", 3);
			Assert::AreEqual(size_t(4), map->size());
		}

		TEST_METHOD(TestGetKeys)
		{
			Map<std::string, int>* map = new Map<std::string, int>();
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
			Map<std::string, int>* map = new Map<std::string, int>();
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
	};
}
