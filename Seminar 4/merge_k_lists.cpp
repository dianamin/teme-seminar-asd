/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {



        multiset <pair <int, int>> minim;



        int list_count = lists.size();



        pair <int, int> p;



        ListNode* sol = NULL;

        ListNode* next_element;

        ListNode* aux;



        if (list_count == 0) return NULL;



        for (int i = 0; i < list_count; i++) {

            if (lists[i] == NULL) continue;

            p.first = lists[i]->val;

            p.second = i;

            minim.insert(p);

        }



        if (minim.empty()) return NULL;



        while(!minim.empty()) {

            p = *(minim.begin());

            minim.erase(minim.begin());



            aux = new ListNode(p.first);



            if (sol == NULL) {

                sol = aux;

                next_element = sol;

            }

            else {

                next_element->next = aux;

                next_element = next_element->next;

            }

            lists[p.second] = lists[p.second]->next;

            if (lists[p.second] != NULL) {

                p.first = lists[p.second]->val;

                minim.insert(p);

            }

        }



        return sol;

    }

};
