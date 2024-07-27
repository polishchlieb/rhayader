#include "dumpNode.hpp"

namespace rhayader {
	void dump(const std::shared_ptr<Node>& node, unsigned int spacing) {
		switch (node->type) {
			case NodeType::AddOpNode:
			case NodeType::SubOpNode:
			case NodeType::MulOpNode:
			case NodeType::DivOpNode:
			case NodeType::GreaterThanOpNode:
			case NodeType::GreaterThanOrEqualOpNode:
			case NodeType::LessThanOpNode:
			case NodeType::LessThanOrEqualOpNode:
			case NodeType::DoubleEqualsOpNode:
			case NodeType::EqualsOpNode:
			case NodeType::DotOpNode:
			case NodeType::AndNode:
			case NodeType::OrNode: {
				// binary ops need to keep the same structure for this to work
				const auto& operatorNode = nodeCast<AddOpNode>(node);

				std::cout << times(" ", spacing) << dumpNodeType(node->type) << std::endl;
				dump(operatorNode->left, spacing + 2);
				dump(operatorNode->right, spacing + 2);
				break;
			}
			case NodeType::NumberNode: {
				const auto& leafNode = nodeCast<NumberNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(node->type) << ": " << leafNode->value << std::endl;
				break;
			}
			case NodeType::NameNode:
			case NodeType::StringNode: {
				const auto& leafNode = nodeCast<StringNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(node->type) << ": " << leafNode->value << std::endl;
				break;
			}
			case NodeType::BooleanNode: {
				const auto& boolNode = nodeCast<BooleanNode>(node);
				std::cout << times(" ", spacing) << "boolean: " << boolNode->value << std::endl;
				break;
			}
			case NodeType::NullNode:
				std::cout << times(" ", spacing) << "null" << std::endl;
				break;
			case NodeType::FuncCallNode: {
				const auto& funcNode = nodeCast<FuncCallNode>(node);

				std::cout << times(" ", spacing)
					<< dumpNodeType(node->type) << ":" << std::endl
					<< times(" ", spacing + 2) << "function: " << std::endl;

				dump(funcNode->name, spacing + 4);

				std::cout << times(" ", spacing + 2) << "arguments: "
					<< std::endl;
				for (const auto& arg : funcNode->arguments)
					dump(arg, spacing + 4);
				break;
			}
			case NodeType::IfNode: {
				const auto n = nodeCast<IfNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(node->type) << ":" << std::endl

					<< times(" ", spacing + 2) << "condition:"
					<< std::endl;

				dump(n->condition, spacing + 4);

				std::cout
					<< times(" ", spacing + 2) << "then:"
					<< std::endl;

				dump(n->body, spacing + 4);

				if (n->elseBody) {
					std::cout
						<< times(" ", spacing + 2) << "else:"
						<< std::endl;

					dump(n->elseBody, spacing + 4);
				}
				break;
			}
			case NodeType::PrototypeNode: {
				const auto n = nodeCast<PrototypeNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(node->type) << ":" << std::endl

					<< times(" ", spacing + 2) << "arguments:"
					<< std::endl;

				for (const auto& arg : n->args)
					dump(arg, spacing + 4);

				std::cout
					<< times(" ", spacing + 2) << "return value:"
					<< std::endl;

				dump(n->returnValue, spacing + 4);
				break;
			}
			case NodeType::BlockNode: {
				const auto n = nodeCast<BlockNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << ":" << std::endl;

				for (const auto& expr : n->nodes)
					dump(expr, spacing + 2);
				break;
			}
			case NodeType::ArrayNode: {
				const auto n = nodeCast<ArrayNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << ":" << std::endl;

				for (const auto& expr : n->elements)
					dump(expr, spacing + 2);
				break;
			}
			case NodeType::ReturnNode: {
				const auto n = nodeCast<ReturnNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << ":" << std::endl;

				dump(n->returnValue, spacing + 2);
				break;
			}
			case NodeType::NegationNode: {
				const auto n = nodeCast<NegationNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << ":" << std::endl;

				dump(n->expression, spacing + 2);
				break;
			}
			case NodeType::ImportNode: {
				const auto n = nodeCast<ImportNode>(node);

				std::string importType = "file";
				if (n->importType == ImportType::dll) importType = "dll";
				else if (n->importType == ImportType::module) importType = "module";

				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << " (" << importType << "):" << n->moduleName << std::endl;
				break;
			}
			case NodeType::WhileLoopNode: {
				const auto n = nodeCast<WhileLoopNode>(node);
				std::cout << times(" ", spacing)
					<< dumpNodeType(n->type) << ":" << std::endl;

				std::cout << times(" ", spacing + 2) << "condition:" << std::endl;
				dump(n->condition, spacing + 4);
				std::cout << times(" ", spacing + 2) << "body:" << std::endl;
				dump(n->body, spacing + 4);
				break;
			}
			case NodeType::ForLoopNode: {
				const auto n = nodeCast<ForLoopNode>(node);
				std::cout << times(" ", spacing) << dumpNodeType(n->type) << ":" << std::endl;

				std::cout << times(" ", spacing + 2) << "iterator:" << std::endl;
				dump(n->iterator, spacing + 4);
				std::cout << times(" ", spacing + 2) << "in iterable:" << std::endl;
				dump(n->iterable, spacing + 4);
				std::cout << times(" ", spacing + 2) << "body:" << std::endl;
				dump(n->body, spacing + 4);
				break;
			}
			case NodeType::PipeOpNode: {
				const auto n = nodeCast<PipeOpNode>(node);
				std::cout << times(" ", spacing) << dumpNodeType(n->type) << ":" << std::endl;

				std::cout << times(" ", spacing + 2) << "value:" << std::endl;
				dump(n->value, spacing + 4);
				std::cout << times(" ", spacing + 2) << "function:" << std::endl;
				dump(n->function, spacing + 4);
				break;
			}
		}
	}
}