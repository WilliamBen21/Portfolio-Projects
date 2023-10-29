#include <string>
#include "Console.h"


using namespace std;

class ShopUtils
{
public:
#ifdef INVENTORY
    static void ShowInventories(const string& playerName, Inventory playerInv, Inventory storeInv)
    {
        Console::SetCursorPosition(2, 2);
        Console::Write(playerName + "'s inventory: ");
        playerInv.DisplayInventory(4, 3);

        Console::SetCursorPosition(39, 2);
        Console::Write("The Store's inventory: ");
        storeInv.DisplayInventory(41, 3);
    }

    static void DoBuy(const string& playerName, Inventory& playerInv, Inventory& storeInv)
    {
        string itemName = "";

        do
        {
            Console::Clear();
            ShowInventories(playerName, playerInv, storeInv);
            Console::SetCursorPosition(5, 18);
            Console::Write("What would you like to buy? (Type the item name): __________\b\b\b\b\b\b\b\b\b\b");

            std::getline(std::cin, itemName);

        } while (itemName.empty());

        Item itemToBuy = storeInv.GetItem(itemName);

        if (itemToBuy.GetCost() == 0)
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("The Store does not have that item!");
            Utility::WaitForEnterKey();
            return;
        }

        if (itemToBuy.GetCost() > playerInv.GetGold())
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("You can not afford that item!");
            Utility::WaitForEnterKey();
            return;
        }

        if (!playerInv.AddItem(itemToBuy))
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("You do not have room for that item!");
            Utility::WaitForEnterKey();
            return;
        }

        playerInv.SetGold(playerInv.GetGold() - itemToBuy.GetCost());
        storeInv.SetGold(storeInv.GetGold() + itemToBuy.GetCost());

        storeInv.RemoveItem(itemName);
    };

    static void DoSell(const string& playerName, Inventory& playerInv, Inventory& storeInv)
    {
        string itemName = "";

        do
        {
            Console::Clear();
            ShowInventories(playerName, playerInv, storeInv);
            Console::SetCursorPosition(5, 18);
            Console::Write("What would you like to sell? (Type the item name): __________\b\b\b\b\b\b\b\b\b\b");
            std::getline(std::cin, itemName);

        } while (itemName.size() == 0);

        Item itemToSell = playerInv.GetItem(itemName);

        if (itemToSell.GetCost() == 0)
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("You do not have that item!");
            Utility::WaitForEnterKey();
            return;
        }

        if (itemToSell.GetCost() > storeInv.GetGold())
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("The Store can not afford to buy that item!");
            Utility::WaitForEnterKey();
            return;
        }

        if (!storeInv.AddItem(itemToSell))
        {
            Console::SetCursorPosition(5, 20);
            Console::Write("The Store does not have room for that item!");
            Utility::WaitForEnterKey();
            return;
        }

        storeInv.SetGold(storeInv.GetGold() - itemToSell.GetCost());
        playerInv.SetGold(playerInv.GetGold() + itemToSell.GetCost());

        playerInv.RemoveItem(itemName);
    }

    static void DoTransaction(const string& playerName, Inventory& playerInv, Inventory& storeInv, bool buy)
    {
        if (buy)
        {
            DoBuy(playerName, playerInv, storeInv);
        }
        else
        {
            DoSell(playerName, playerInv, storeInv);
        }
    }

#endif // INVENTORY

};
