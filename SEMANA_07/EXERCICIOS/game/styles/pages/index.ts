import styled from 'styled-components'

export const PageContainer = styled.div`
    min-height: 100vh;
    position: relative;
`
export const Container = styled.div`
    background-color: ${(props) => props.theme.colors.primaryDark};
    position: absolute;
    top: 4rem;
    left: 4rem;
    bottom: 4rem;
    right: 4rem;
    border-radius: 1rem;
    box-shadow: 0 0 1.5rem rgba(0, 0, 0, 0.8);
`
export const Title = styled.h1`
    text-align: center;
    font-size: 4.6rem;
    font-weight: 700;
    color: ${(props) => props.theme.colors.white};
    margin-top: 8rem;
    margin-bottom: 4rem;
`

export const Description = styled.h3`
    font-weight: 300;
    font-size: 2rem;
    color: ${(props) => props.theme.colors.white};
    margin: 2rem;
    text-align: center;
`

export const Timer = styled.div`
    text-align: center;
    color: ${(props) => props.theme.colors.white};
    margin-top: 6rem;
    font-size: 2rem;
    font-weight: 600;
`

export const Winner = styled.h5`
    position: absolute;
    top: 60%;
    left: 50%;
    transform: translate(-50%, -50%);
    font-size: 3rem;
    color: ${(props) => props.theme.colors.white};
    text-align: center;
`
