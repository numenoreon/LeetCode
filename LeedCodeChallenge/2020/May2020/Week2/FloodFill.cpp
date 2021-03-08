class Solution {

void dfs(vector<vector<int>>& image, int posX, int posY, int oldColor, int newColor){
    if(posX >= image.size() || posX < 0 || posY >= image[posX].size() || posY < 0 || image[posX][posY]!=oldColor)        
        return ;
    
    image[posX][posY]=newColor;
    dfs(image, posX+1, posY, oldColor, newColor);
    dfs(image, posX-1, posY, oldColor, newColor);
    dfs(image, posX, posY+1, oldColor, newColor);
    dfs(image, posX, posY-1, oldColor, newColor);
}
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)
            return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};