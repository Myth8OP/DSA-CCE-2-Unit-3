#include <iostream>
#include <string>
#include <cstdlib>
#include "../include/UILayoutTree.hpp"

void clearScreen() 
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void displayHeader() 
{
    clearScreen();
    std::cout << "   _   _ ___   _____ ____  _____ _____ \n";
    std::cout << "  | | | |_ _| |_   _|  _ \\| ____| ____|\n";
    std::cout << "  | | | || |    | | | |_) |  _| |  _|  \n";
    std::cout << "  | |_| || |    | | |  _ <| |___| |___ \n";
    std::cout << "   \\___/|___|   |_| |_| \\_\\_____|_____|\n";
    std::cout << "\n";
    std::cout << "     RTL/LTR BINARY TREE MIRRORING ENGINE     \n";
    std::cout << "==============================================\n";
}

void pauseMenu() 
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() 
{
    UILayoutTree uiManager;

    std::cout << "Initializing Dynamic Binary Trees for UI DOM...\n";

    //Build Original Left-to-Right (LTR) Layout Tree
    UINode* originalLTR = new UINode("AppWindow");
    originalLTR->left = new UINode("Sidebar");
    originalLTR->right = new UINode("MainBody");
    originalLTR->left->left = new UINode("NavMenu");
    originalLTR->left->right = new UINode("Profile");
    originalLTR->right->left = new UINode("Feed");
    originalLTR->right->right = new UINode("Ads");

    //Build a corrupted tree to test the false condition
    UINode* corruptedTree = new UINode("AppWindow");
    corruptedTree->left = new UINode("MainBody");
    corruptedTree->right = new UINode("Sidebar");
    corruptedTree->left->left = new UINode("Ads");
    corruptedTree->left->right = new UINode("ERROR_NODE"); 

    UINode* generatedRTL = NULL;

    int choice = 0;
    while (choice != 5) 
    {
        displayHeader();
        std::cout << " [1] View Original LTR UI Layout (Binary Tree)\n";
        std::cout << " [2] Generate RTL Mirror Layout (Invert Tree)\n";
        std::cout << " [3] Verify Generated RTL is a perfect mirror\n";
        std::cout << " [4] Verify a corrupted layout (False Test)\n";
        std::cout << " [5] Exit System\n";
        std::cout << "----------------------------------------------\n";
        std::cout << "Enter command: ";
        
        if (!(std::cin >> choice)) 
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) 
        {
            case 1:
                displayHeader();
                std::cout << "--- Original Left-to-Right (LTR) UI Layout ---\n\n";
                uiManager.print2DTree(originalLTR, 0);
                pauseMenu();
                break;
            case 2:
                displayHeader();
                if (generatedRTL != NULL) 
                {
                    uiManager.destroyTree(generatedRTL); 
                }
                std::cout << "Applying Traversal to swap Left & Right nodes...\n\n";
                generatedRTL = uiManager.createMirror(originalLTR);
                
                std::cout << "--- New Right-to-Left (RTL) Mirror Layout ---\n\n";
                uiManager.print2DTree(generatedRTL, 0);
                pauseMenu();
                break;
            case 3:
                displayHeader();
                std::cout << "Comparing Original LTR Tree with Generated RTL Tree...\n\n";
                if (generatedRTL == NULL) 
                {
                    std::cout << "Error: Please generate the mirror layout first (Option 2).\n";
                } else 
                {
                    if (uiManager.areMirrors(originalLTR, generatedRTL)) 
                    {
                        std::cout << "[SUCCESS] The layouts are perfect mirror images!\n";
                        std::cout << "RTL Language Support verified.\n";
                    } else 
                    {
                        std::cout << "[FAILED] The layouts do not match.\n";
                    }
                }
                pauseMenu();
                break;
            case 4:
                displayHeader();
                std::cout << "Comparing Original LTR Tree with a Corrupted RTL Tree...\n\n";
                std::cout << "Expected Output: FAILED (Corrupted tree has an 'ERROR_NODE')\n\n";
                
                if (uiManager.areMirrors(originalLTR, corruptedTree)) 
                {
                    std::cout << "[SUCCESS] The layouts are perfect mirror images!\n";
                } else 
                {
                    std::cout << "[FAILED] Structural validation failed. Trees are not mirrors.\n";
                }
                pauseMenu();
                break;
            case 5:
                displayHeader();
                std::cout << "Safely invoking destructors & freeing dynamic memory...\n";
                uiManager.destroyTree(originalLTR);
                if (generatedRTL != NULL) uiManager.destroyTree(generatedRTL);
                uiManager.destroyTree(corruptedTree);
                std::cout << "System shutdown complete. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid input. Please try again.\n";
                break;
        }
    }
    return 0;
}