/*上图在插入前，AVL树是平衡的，新节点插入到30的左子树(注意：此处不是左孩子)中，30左子树增加
了一层，导致以60为根的二叉树不平衡，要让60平衡，只能将60左子树的高度减少一层，右子树增加一
层，即将左子树往上提，这样60转下来，因为60比30大，只能将其放在30的右子树，而如果30有右子树，右
子树根的值一定大于30，小于60，只能将其放在60的左子树，旋转完成后，更新节点的平衡因子即可。在旋
转过程中，有以下几种情况需要考虑：
1. 30节点的右孩子可能存在，也可能不存在
2. 60可能是根节点，也可能是子树
如果是根节点，旋转完成后，要更新根节点
如果是子树，可能是某个节点的左子树，也可能是右子树
*/
void _RotateR(PNode pParent) {
	// pSubL: pParent的左孩子
	// pSubLR: pParent左孩子的右孩子，注意：该
	PNode pSubL = pParent->_pLeft;
	PNode pSubLR = pSubL->_pRight;
	// 旋转完成之后，30的右孩子作为双亲的左孩子
	pParent->_pLeft = pSubLR;
	// 如果30的左孩子的右孩子存在，更新亲双亲
	if (pSubLR)
		pSubLR->_pParent = pParent;
	// 60 作为 30的右孩子
	pSubL->_pRight = pParent;
	// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
	PNode pPParent = pParent->_pParent;
	// 更新60的双亲
	pParent->_pParent = pSubL;
	// 更新30的双亲
	pSubL->_pParent = pPParent;
	// 如果60是根节点，根新指向根节点的指针
	if (NULL == pPParent)
	{
		_pRoot = pSubL;
		pSubL->_pParent = NULL;
	}
	else
	{
		// 如果60是子树，可能是其双亲的左子树，也可能是右子树
		if (pPParent->_pLeft == pParent)
			pPParent->_pLeft = pSubL;
		else
			pPParent->_pRight = pSubL;
	}
	// 根据调整后的结构更新部分节点的平衡因子
	pParent->_bf = pSubL->_bf = 0;
}