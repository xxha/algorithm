/*  AVL-height by BNJ from HLJ
 *  保存子树高度，代替平衡因子，使用指针引用，降低实现复杂度
 *  已封装成模板类方便使用
 *  附测试程序一个
 *  请大牛发表评论
 */
 
#include <iostream>
using namespace std;
 
namespace bnj{
	template <typename T>
	class AVL{
	private:
		class tnode;
		typedef tnode* tptr;
		class tnode{
		public:
			T data;
			tptr lchild, rchild;
			int height;
			tnode():lchild(0),rchild(0),height(1){};
			tnode(T _data):data(_data),lchild(0),rchild(0),height(1){};
			int get_height(){if(this)return height;return 0;};
			void recount(){
				if(!this)return;
				int lh=lchild->get_height();
				int rh=rchild->get_height();
				height=((lh>rh)?lh:rh)+1;
			};
		}*root;
		void ccw(tptr &t){
			tptr d=t->rchild->lchild;
			t->rchild->lchild=t;
			t=t->rchild;
			t->lchild->rchild=d;
			t->lchild->recount();t->recount();
		};
		void cw(tptr &t){
			tptr d=t->lchild->rchild;
			t->lchild->rchild=t;
			t=t->lchild;
			t->rchild->lchild=d;
			t->rchild->recount();t->recount();
		};
		void balance_left(tptr &t){
			int lh=t->lchild->lchild->get_height();
			int rh=t->lchild->rchild->get_height();
			if(lh>=rh)cw(t);
			else{ccw(t->lchild);cw(t);};
		}//balance_left
		void balance_right(tptr &t){
			int rh=t->rchild->rchild->get_height();
			int lh=t->rchild->lchild->get_height();
			if(rh>=lh)ccw(t);
			else{cw(t->rchild);ccw(t);};
		}//balance_right
		void insert_(tptr &t, T data){
			if(!t){t=new tnode(data);return;};
			if(data<=t->data){
				insert_(t->lchild, data);
				if(t->lchild->get_height()-t->rchild->get_height()>1)balance_left(t);
			}else{
				insert_(t->rchild, data);
				if(t->rchild->get_height()-t->lchild->get_height()>1)balance_right(t);
			}
			t->recount();
		}//insert_
		void remove_(tptr &t, T data){
			if(!t)return;
			if(data==t->data){
				if(t->lchild && t->rchild){
					tptr p=t->rchild;
					for(;p->lchild;p=p->lchild);
					t->data=p->data;
					remove_(t->rchild, p->data);
				        if(t->lchild->get_height()-t->rchild->get_height()>1)balance_left(t);
				}else if(t->lchild){
					t->data=t->lchild->data;
					t->lchild=0;
				}else if(t->rchild){
					t->data=t->rchild->data;
					t->rchild=0;
				}else t=0;
			}else if(data<t->data){
				remove_(t->lchild, data);
				if(t->rchild->get_height()-t->lchild->get_height()>1)balance_right(t);
			}else{
				remove_(t->rchild, data);
				if(t->lchild->get_height()-t->rchild->get_height()>1)balance_left(t);
			}
			t->recount();
		}//remove_
		void inorder_(tptr t, void (*visit)(const T*)){
			if(t){
				inorder_(t->lchild, visit);
				visit(&(t->data));
				inorder_(t->rchild, visit);
			}
		}
	public:
		AVL():root(0){};
		void insert(T data){insert_(root, data);};
		void remove(T data){remove_(root, data);};
		void inorder(void (*visit)(const T*)){inorder_(root, visit);};
	};
	template <typename T>
	void sample_visit(const T*a){cout<<(*a)<<" ";}
	void avl_test(){
		AVL<int> my_avl;
		char c;
		int i;
		for(cin>>c;c!='q';cin>>c)switch(c){
			case 'i':
				cin>>i;
				my_avl.insert(i);
				break;
			case 'r':
				cin>>i;
				my_avl.remove(i);
				break;
			case 'p':
				my_avl.inorder(sample_visit);
				cout<<endl;
		}
	}
}
 
int main(){
	bnj::avl_test();
	return 0;
}
