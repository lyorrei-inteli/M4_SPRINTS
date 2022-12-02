import Head from 'next/head'
import { useCallback, useEffect, useState } from 'react'
import { Button } from '../components/button'
import Keys from '../components/keys'
import { Container, Description, PageContainer, Timer, Title, Winner } from '../styles/pages'
import axios from 'axios'

const Home = () => {
    const [isRunning, setIsRunning] = useState(false)
    const [timer, setTimer] = useState(10)
    const [playerOneCount, setPlayerOneCount] = useState(0)
    const [playerTwoCount, setPlayerTwoCount] = useState(0)

    useEffect(() => {
        if (isRunning && timer !== 0) {
            const timeout = setTimeout(() => {
                setTimer(timer - 1)
            }, 1000)

            return () => {
                clearTimeout(timeout)
            }
        }
        if (timer == 0) {
            setIsRunning(false)

            if (playerOneCount > playerTwoCount) {
                axios.get('http://10.10.0.2:80/playerone').catch(err => console.log(err))
            } else if (playerOneCount < playerTwoCount) {
                axios.get('http://10.10.0.2:80/playertwo').catch(err => console.log(err))
            } else {
                alert('Empate!')
            }
        }
    }, [timer, isRunning])

    const startGame = () => {
        setPlayerOneCount(0)
        setPlayerTwoCount(0)
        setIsRunning(true)
        setTimer(10)
    }

    return (
        <>
            <Head>
                <title>Game</title>
            </Head>
            <PageContainer>
                <Container>
                    <Title>The click game!</Title>
                    <Description>
                        A regra é simples: <br />A pessoa que mais clicar em sua tecla durante o jogo é a vencedora!
                    </Description>
                    {isRunning ? (
                        <Timer>
                            Clique! <br /> {timer}s
                        </Timer>
                    ) : (
                        <Button onClick={startGame}>Start</Button>
                    )}

                    <Keys
                        playerOneCount={playerOneCount}
                        playerTwoCount={playerTwoCount}
                        setPlayerOneCount={setPlayerOneCount}
                        setPlayerTwoCount={setPlayerTwoCount}
                        isRunning={isRunning}
                    />
                    {(playerOneCount > 0 || playerTwoCount > 0) && !isRunning && (
                        <Winner>
                            {playerOneCount > playerTwoCount ? 'Player One ganhou!' : 'Player Two ganhou!'}
                            <br />
                            {playerOneCount} | {playerTwoCount}
                        </Winner>
                    )}
                </Container>
            </PageContainer>
        </>
    )
}

export default Home
