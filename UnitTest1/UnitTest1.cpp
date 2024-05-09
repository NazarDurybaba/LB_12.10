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
			Node* root = buildRandomTree(10); // �������� ������ � 10 ���������� �����
			int numNodes = countNodes(root); // ���������� ������� ����� � �����
			Assert::AreEqual(31, numNodes); // ��������, �� ������ �� 10 �����
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
			int numNodes = countNodes(root); // ���������� ������� ����� � �����
			Assert::AreEqual(7, numNodes); // ��������, �� ������ �� 7 �����
		}
	};
}
