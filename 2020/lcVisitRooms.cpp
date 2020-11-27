
class Solution{
	private:
	int n;
void canVisitAllRooms(vector<vector<int>>& rooms, int room, int* has){

	for(int i=0;i<rooms[room].size();i++){
	if(has[rooms[room][i]]==0){
		has[rooms[room][i]]=1;
		canVisitAllRooms(rooms, rooms[room][i], has);
}
}
}

bool checkAllRoomsVisited(int* has){
	for(int i=0;i<n;i++){
	if(has[i]==0)
		return false;
}
return true;
}

public:
	bool canVisitAllRooms(vector<vector<int>>& rooms){
		n = rooms.size();
		int has[n];
		for(int i=0;i<n;i++){
			has[i]=0;
        }
        has[0]=1;
        canVisitAllRooms(rooms,0,has);
        return checkAllRoomsVisited(has);
    }
};
