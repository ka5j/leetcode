/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList = new ListNode(0);
        ListNode* outList = sumList;

        ListNode* l1Copy = l1;
        ListNode* l2Copy = l2;

        int numRuns = 0;

        bool needCarry = false;

        bool bothListsDone = false;

        int l1CurrSumVal = 0;
        int l2CurrSumVal = 0;

        int sumListVal = 0;

        while(!bothListsDone)
        {
            numRuns++;

            if((l1Copy != NULL) && (l2Copy != NULL))
            {
                l1CurrSumVal = l1Copy->val;
                l2CurrSumVal = l2Copy->val;

                l1Copy = l1Copy->next;
                l2Copy = l2Copy->next;
            }
            else if((l1Copy == NULL) && (l2Copy != NULL))
            {
                l1CurrSumVal = 0;

                l2CurrSumVal = l2Copy->val;
                l2Copy = l2Copy->next;
            }
            else if((l2Copy == NULL) && (l1Copy != NULL))
            {
                l2CurrSumVal = 0;

                l1CurrSumVal = l1Copy->val;
                l1Copy = l1Copy->next;
            }
            else if((l1Copy == NULL) && (l2Copy == NULL))
            {
                if(!needCarry)
                {
                    bothListsDone = true;
                    break;
                }
                else
                {
                    l1CurrSumVal = 0;
                    l2CurrSumVal = 0;
                }
            }

            sumListVal = l1CurrSumVal + l2CurrSumVal + (int)needCarry;

            if(sumListVal > 9)
            {
                needCarry = true;
                sumListVal = sumListVal - 10;
            }
            else
            {
                needCarry = false;
            }

            if(numRuns == 1)
            {
                sumList->val = sumListVal;
            }

            else if(numRuns > 1)
            {
                ListNode* currSum = new ListNode(sumListVal);
                sumList->next = currSum;
                sumList = sumList->next;
            }

        }
        return outList;
    }
};
