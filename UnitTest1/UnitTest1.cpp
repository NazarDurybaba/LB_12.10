#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBuildRandomTree)
		{
			Node* root = buildRandomTree(10); // Побудова дерева з 10 випадкових вузлів
			int numNodes = countNodes(root); // Обчислення кількості вузлів у дереві
			Assert::AreEqual(31, numNodes); // Перевірка, чи дерево має 10 вузлів
		}

		TEST_METHOD(TestCountNodes)
		{
			Node* root = nullptr;
			insertNode(root, 10);
			insertNode(root, 5);
			insertNode(root, 15);
			insertNode(root, 3);
			insertNode(root, 7);
			insertNode(root, 12);
			insertNode(root, 17);
			int numNodes = countNodes(root); // Обчислення кількості вузлів у дереві
			Assert::AreEqual(7, numNodes); // Перевірка, чи дерево має 7 вузлів
		}
	};
}
