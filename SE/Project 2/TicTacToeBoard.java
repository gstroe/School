package com.GUI;

import javax.swing.*;
import java.awt.event.*;
import java.util.Random;

/**
 * Created by Gabe on 10/30/2016.
 */
public class TicTacToeBoard {
    // region Menu items
    private JPanel pnMain;
    private JPanel pnMenu;
    private JLabel lbMenuTitle;
    private JPanel pnMenuButtonLayout;
    private JButton btMenu1P;
    private JButton btMenu2P;
    private JComboBox cbMenuDifficulty;
    private JPanel pnBoard;
    private JPanel pnBoardTopLeft;
    private JPanel pnBoardTopCenter;
    private JPanel pnBoardGame;
    private JPanel pnBoardTopRight;
    private JPanel pnBoardMidLeft;
    private JPanel pnBoardMidCenter;
    private JPanel pnBoardMidRight;
    private JPanel pnBoardBotLeft;
    private JPanel pnBoardBotCenter;
    private JPanel pnBoardBotRight;
    private JLabel lbBoardTopLeft;
    private JLabel lbBoardTopRight;
    private JLabel lbBoardTopCenter;
    private JLabel lbBoardMidLeft;
    private JLabel lbBoardMidCenter;
    private JLabel lbBoardMidRight;
    private JLabel lbBoardBotLeft;
    private JLabel lbBoardBotCenter;
    private JLabel lbBoardBotRight;
    private JPanel pnBoardScore;
    private JLabel lbBoardP1;
    private JPanel pnBoardP1;
    private JPanel pnBoardScoreValue;
    private JPanel pnBoardP2;
    private JLabel lbBoardP2;
    private JLabel lbBoardScoreTitle;
    private JLabel lbBoardTurnP1;
    private JLabel lbBoardTurnP2;
    private JLabel lbBoardScore;
    //endregion

    //region Global Flags and Variables
    // For arrays Player 1 is 0 and Player 2 is 1.
    boolean onePlayerMode = false; // false if in two player. true if in one player mode
    int difficulty = 0; // 0-2 from easy, med or hard
    int startingPlayer = 0; // indicates who starts 0 or 1
    int winner = 2; // the winner of a match. 0 is player 1, 1 is player 2 and, 2 is a tie.
    int[] scoreP = {0,0}; // Score for player 1 and 2
    int currentPlayer = 0; // the current players turn 0 or 1
    boolean[][] boardFill; // if the board has a character on it. [0][X] is a player 1 spot, [1][X] is a player 2 spot, and [2][X] is a general spot.
    String[] charP = {"X","O"}; // Array with the chars of each player


    //endregion



    //enables all of the actions for the GUI items
    public TicTacToeBoard() {
        boardFill = new boolean[3][9]; // Initialize the Board Spots

        //region Listeners
        //Action listener for the 1 Player Mode Button
        btMenu1P.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Set Correct Flags
                onePlayerMode = true;
                startingValues(); // values that are the same regardless of one or two players
                lbBoardP2.setText("Computer (" + charP[1] + ")");
                difficulty = cbMenuDifficulty.getSelectedIndex(); // set the difficulty
            }
        });

        //Action listener for the 2 Player Mode Button
        btMenu2P.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Set Correct Flags
                onePlayerMode = false;
                startingValues(); // values that are the same regardless of one or two players
                lbBoardP2.setText("Player 2 (" + charP[1] + ")");
            }
        });

        //TopLeft Click
        pnBoardTopLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 0; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardTopLeft.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //TopCenter Click
        pnBoardTopCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 1; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardTopCenter.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //TopRight Click
        pnBoardTopRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 2; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardTopRight.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //MidLeft Click
        pnBoardMidLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 3; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardMidLeft.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //MidCenter Click
        pnBoardMidCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 4; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardMidCenter.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //MidRight Click
        pnBoardMidRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 5; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardMidRight.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //BotLeft Click
        pnBoardBotLeft.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 6; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardBotLeft.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //BotCenter Click
        pnBoardBotCenter.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 7; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardBotCenter.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //BotRight Click
        pnBoardBotRight.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);

                //region Click Logic
                int spot = 8; // A temp variable to make this easier to implement in the other panels
                // Check if spot is taken
                if (boardFill[2][spot] == false) {
                    boardFill[currentPlayer][spot] = true;
                    boardFill[2][spot] = true;
                    lbBoardBotRight.setText(charP[currentPlayer]);

                    // check if someone won
                    if (winCheck()) {
                        gameOver(); // to to game over logic
                    }
                    else {
                        // Change turns
                        if (currentPlayer == 0) {
                            currentPlayer = 1;
                        } else {
                            currentPlayer = 0;
                        }
                        // Show who's turn it is
                        changeTurnIndicator();

                        // AI Move if one player mode active
                        if (onePlayerMode) {
                            AI_Logic();
                        }
                    }
                } //endregion
            }
        });

        //endregion

    }

    // AI Logic Function
    private void AI_Logic() {
        int spotChosen = 0;

        //region AI Logic
        Random random = new Random();
        int placement = random.nextInt(9); // get random placement
        while (boardFill[2][placement] == true){ // cycle through if already chosen
            if(placement<8) {
                placement++;
            }
            else {
                placement = 0;
            }
        }
        // place the value
        boardFill[1][placement] = true;
        boardFill[2][placement] = true;
        spotChosen = placement;

        //endregion

        //region Placing the mark Chosen
        if (spotChosen == 0) { lbBoardTopLeft.setText(charP[1]); }
        else if (spotChosen == 1) { lbBoardTopCenter.setText(charP[1]); }
        else if (spotChosen == 2) { lbBoardTopRight.setText(charP[1]); }
        else if (spotChosen == 3) { lbBoardMidLeft.setText(charP[1]); }
        else if (spotChosen == 4) { lbBoardMidCenter.setText(charP[1]); }
        else if (spotChosen == 5) { lbBoardMidRight.setText(charP[1]); }
        else if (spotChosen == 6) { lbBoardBotLeft.setText(charP[1]); }
        else if (spotChosen == 7) { lbBoardBotCenter.setText(charP[1]); }
        else if (spotChosen == 8) { lbBoardBotRight.setText(charP[1]); }
        //endregion

        // check if someone won
        if (winCheck()) {
            gameOver(); // to to game over logic
        }

        // Switch Back to player ones turn
        currentPlayer = 0;
        // Show who's turn it is
        changeTurnIndicator();
    }

    // End Game Pop Up
    private void gameOver() {
        Object[] options = {"Rematch", "Main Menu"}; // button options
        // check the who won
        String winnerName = "";
        if (winner == 0) {
            winnerName = lbBoardP1.getText() + " has Won!";
            scoreP[0]++;
        }
        else if (winner == 1) {
            winnerName = lbBoardP2.getText() + " has Won!";
            scoreP[1]++;
        }
        else {
            winnerName = "The Game is a Draw!";
        }

        // Change in the score board
        lbBoardScore.setText(scoreP[0] + " - " + scoreP[1]);

        // Prompt for rematch or return to main menu
        int choice = JOptionPane.showOptionDialog(null,"Rematch or return to main menu?",winnerName, JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[0]);

        // Change to the correct game screen
        if (choice == 0) { // rematch
            // Swap Starting Player
            if (startingPlayer == 0 ) {
                startingPlayer = 1;
            }
            else {
                startingPlayer = 0;
            }
            // set the correct Chars
            if(startingPlayer == 0) {
                charP[0] = "X";
                charP[1] = "O";
            }
            else {
                charP[0] = "O";
                charP[1] = "X";
            }
            // Change the players Name
            lbBoardP1.setText("Player 1 (" + charP[0] + ")");
            if (onePlayerMode) { lbBoardP2.setText("Computer (" + charP[1] + ")"); }// If there is an AI for Player 2
            else { lbBoardP2.setText("Player 2 (" + charP[1] + ")"); } // if they are a human player

            currentPlayer = startingPlayer; // set the current player to the starting player
            // Show who's turn it is
            changeTurnIndicator();
            //Reset the Board
            boardClear();
            // set the score
            lbBoardScore.setText(scoreP[0] + " - " + scoreP[1]);

            // Check if AI is starting
            if (onePlayerMode && startingPlayer == 1) {
                AI_Logic();
            }
        }
        else { // Main menu Choice
            pnMenu.setVisible(true);
            pnBoard.setVisible(false);
        }
    }

    // Change the visibility of the turns indicator
    private void changeTurnIndicator() {
        if (currentPlayer == 0){
            lbBoardTurnP1.setVisible(true);
            lbBoardTurnP2.setVisible(false);
        }
        else {
            lbBoardTurnP1.setVisible(false);
            lbBoardTurnP2.setVisible(true);
        }
    }

    // Win condition check
    private boolean winCheck() {
        String p1Nums = ""; // List Of numbers selected by player 1
        String p2Nums = ""; // List Of numbers selected by player 2
        int total = 0; // total for checking for draws

        // Count totals for all the spaces being taken up
        for(int i=0; i<9; i++)
        {
            if (boardFill[0][i]) { //if the spot is filled ad the number to the list for player 2
                p1Nums += i;
            }

            if (boardFill[1][i]) { //if the spot is filled ad the number to the list for player 2
                p2Nums += i;
            }

            if (boardFill[2][i]) { // see if it is filled at all, for draws total should be 511
                total += Math.pow(2.0,(double)i);
            }
        }

        //region Check if player 1 won
        if(p1Nums.contains("0")&&p1Nums.contains("1")&&p1Nums.contains("2")) { // Top in a row
            winner = 0;
            return true;
        }
        if(p1Nums.contains("3")&&p1Nums.contains("4")&&p1Nums.contains("5")) { // Mid in a rom
            winner = 0;
            return true;
        }
        if(p1Nums.contains("6")&&p1Nums.contains("7")&&p1Nums.contains("8")) { // Bot in a row
            winner = 0;
            return true;
        }
        if(p1Nums.contains("0")&&p1Nums.contains("3")&&p1Nums.contains("6")) { // Left in a row
            winner = 0;
            return true;
        }
        if(p1Nums.contains("1")&&p1Nums.contains("4")&&p1Nums.contains("7")) { // Center in a row
            winner = 0;
            return true;
        }
        if(p1Nums.contains("2")&&p1Nums.contains("5")&&p1Nums.contains("8")) { // Right in a row
            winner = 0;
            return true;
        }
        if(p1Nums.contains("0")&&p1Nums.contains("4")&&p1Nums.contains("8")) { // Diag from TopLeft
            winner = 0;
            return true;
        }
        if(p1Nums.contains("2")&&p1Nums.contains("4")&&p1Nums.contains("6")) { // Diag from TopRight
            winner = 0;
            return true;
        }
        //endregion

        //region Check if player 2 won
        if(p2Nums.contains("0")&&p2Nums.contains("1")&&p2Nums.contains("2")) { // Top in a row
            winner = 1;
            return true;
        }
        if(p2Nums.contains("3")&&p2Nums.contains("4")&&p2Nums.contains("5")) { // Mid in a rom
            winner = 1;
            return true;
        }
        if(p2Nums.contains("6")&&p2Nums.contains("7")&&p2Nums.contains("8")) { // Bot in a row
            winner = 1;
            return true;
        }
        if(p2Nums.contains("0")&&p2Nums.contains("3")&&p2Nums.contains("6")) { // Left in a row
            winner = 1;
            return true;
        }
        if(p2Nums.contains("1")&&p2Nums.contains("4")&&p2Nums.contains("7")) { // Center in a row
            winner = 1;
            return true;
        }
        if(p2Nums.contains("2")&&p2Nums.contains("5")&&p2Nums.contains("8")) { // Right in a row
            winner = 1;
            return true;
        }
        if(p2Nums.contains("0")&&p2Nums.contains("4")&&p2Nums.contains("8")) { // Diag from TopLeft
            winner = 1;
            return true;
        }
        if(p2Nums.contains("2")&&p2Nums.contains("4")&&p2Nums.contains("6")) { // Diag from TopRight
            winner = 1;
            return true;
        }
        //endregion

        // see if its a draw
        if (total == 511) {
            winner = 2;
            return true;
        }

        // No exit so this is false
        return false;
    }

    // Clear the Board
    private void boardClear() {
        // clear the arrays
        for(int i=0; i<3; i++){
            for(int j=0; j<9; j++){
                boardFill[i][j] = false;
            }
        }
        // clear the visuals
        lbBoardTopLeft.setText("");
        lbBoardTopCenter.setText("");
        lbBoardTopRight.setText("");
        lbBoardMidLeft.setText("");
        lbBoardMidCenter.setText("");
        lbBoardMidRight.setText("");
        lbBoardBotLeft.setText("");
        lbBoardBotCenter.setText("");
        lbBoardBotRight.setText("");
    }

    // Starting Variables when comming from the main menu
    private void startingValues() {
        pnMenu.setVisible(false);
        pnBoard.setVisible(true);
        scoreP[0] = 0;
        scoreP[1] = 0;
        winner = 2;
        startingPlayer = 0;
        // Change Player 1 and 2'name Depending on who starts
        if(startingPlayer == 0) {
            // set the correct Chars
            charP[0] = "X";
            charP[1] = "O";
            // Change the players Name
            lbBoardP1.setText("Player 1 (" + charP[0] + ")");
            if (onePlayerMode) { lbBoardP2.setText("Computer (" + charP[1] + ")"); }// If there is an AI for Player 2
            else { lbBoardP2.setText("Player 2 (" + charP[1] + ")"); } // if they are a human player
        }
        currentPlayer = startingPlayer;
        // Show who's turn it is
        changeTurnIndicator();
        //Reset the Board
        boardClear();
        // set the score
        lbBoardScore.setText(scoreP[0] + " - " + scoreP[1]);
    }

    // start a JFrame application
    public static void main(String[] args){
        JFrame frame = new JFrame("Tic Tac Toe");
        frame.setContentPane(new TicTacToeBoard().pnMain);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }
}
