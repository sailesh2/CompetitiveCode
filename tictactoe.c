//models


class Client
{
    private string name;
    private string status;
    private char val;
    public Client(string name,char val)
    {
        this.name=name;
        this.val=val;
        status="going";
    }
    public void move(int x,int y)
    {
        if( GameBoard.check(x,y) )
        {
            GameBoard.insert(x,y,val);
            if( GameBoard.canWin(name))
            {
                status="win";
            }
        }
    }
}


class GameBoard
{
    private Client player1;
    private Client player2;
    private char board[3][3];
    private Server logicBuilder;

    public GameBoard()
    {
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                board[i][j]='N';
            }
        }
        logicBuilder new Server();
        logicBuilder.board=board;

    }

    public boolean check(int x,int y)
    {
        if(board[x][y]=='N')
        return true;
        else
        return false;
    }

    public void insert(int x,int y,int val)
    {
        board[x][y]=val;
    }

    public boolean canWin(string name)
    {
        if(player1.name==name)
        {
            return logicBuilder.check(player1);
        }
        else
        {
            return logicBuilder.check(player2);
        }
    }
}


class Server
{
    private char board[3][3];
    public Server()
    {
    }

    public boolean check(Client player)
    {
        char req=player.val;
        int cnt=0;
        if(board[0][0]==req && board[0][1]==req && board[0][2]==req)
            cnt=1;

        if(board[0][0]==req && board[1][0]==req && board[2][0]==req)
            cnt=1;

        if(board[0][0]==req && board[1][1]==req && board[2][2]==req)
            cnt=1;

        if(board[0][2]==req && board[1][1]==req && board[2][0]==req)
            cnt=1;

        if(cnt==1)
        return true;
        else
        return false;
    }
}


//view


<html>
    <head>
        <p>TIC TAC TOE</p>
    </head>
    <script>
        if
        function check()={
            val=table.row.value;
            x=rowno;
            y=coloumnno;
            player=name;
            //calls a register controller check fun
            check(val,x,y,name);
        }
    </script>
    <body>
        @{
            if(viewBag.status=="Win")
            {
                <P>GAME COMPLETED</p>
            }
        }
        <div>Register</div>
        <form method=post action=@register controller>
            name:<input type=text name='name'>
            insert your value:<input type=text name='val'>
            submit:<input type="submit">
        </form>
        <table>
            <tr>  <td> <input type=text> </td> <td> <input type=text> </td> <td> <input type=text> </td></tr>
            <tr>  <td> <input type=text> </td> <td> <input type=text> </td> <td> <input type=text> </td></tr>
            <tr>  <td> <input type=text> </td> <td> <input type=text> </td> <td> <input type=text> </td></tr>
        </table>
        click here after inserting in your board:<button onClick="check()">
    </body>
</html>


//controllers
class Register
{
    Client player1,player2;
    Register()
    {

    }
    public view action()
    {
        string name=request[].get('name');

        char val=request[].get('val');
        if(player1==null)
            player1=new Client(name,val);
        else
            player2=new Client(name,val);

        return view();
    }

    public view check(int val,string name,int x,int y)
    {
        if(player1.name==name)
        {
            player1.move(x,y);
            viewBag.status=player1.status;
        }
        else
        {
            player2.move(x,y);
            viewBag.status=player2.status;
        }
        return view();
    }
}

